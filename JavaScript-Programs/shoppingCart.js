"use strict";

///////////////////////////////////////////////////////////////////
/*
Requirements:
1) I have selected DOM Elments that you need at the top; and you need to implement your own version of it.
2) Alert library, I have used Qual Alert and Sweet Alert, you can use your own popup and can tweak the code as you want
3) Axios to make POST request to the server by sending cart details to the server
*/

const cartBtn = document.querySelectorAll(".add-to-cart");
const badge = document.getElementById("cart-badge");
const mobileBadge = document.getElementById("cart-badge-mobile");
const cartTotalPrice = document.getElementById("cart-total-price");
const cartBody = document.getElementById("cart-body");
const clearCartBtn = document.getElementById("clear-cart-btn");
const checOutBtn = document.getElementById("checkout-btn");
const cartTaxPrice = document.getElementById("tax-amount");
const cartShippingCharge = document.getElementById("shipping-charge");
const cartGrandTotal = document.getElementById("grand-total-price");

const showLoader = function () {
  loader.classList.remove("hidden-el");
  preLoader.classList.remove("hidden-el");
  overlay.classList.remove("hidden-el");
};

const hideLoader = function () {
  loader.classList.add("hidden-el");
  preLoader.classList.add("hidden-el");
  overlay.classList.add("hidden-el");
};

const localStorageName = "shoppingCart";
let cartString = localStorage.getItem(localStorageName);
let cart = [];
let shippingCharge = 0;

if (!cartString) {
  cartString = JSON.stringify(cart);
}

cart = JSON.parse(cartString);

const getIndex = (id) => cart.findIndex((el) => el.id === +id);

function cancelBtnFunction() {
  close_qual();
}

function userConfirmation(msg, functionString) {
  const a = Qual.confirm(
    msg,
    "",
    war,
    "YES",
    "Cancel",
    functionString,
    "cancelBtnFunction"
  );
}

function getCartData() {
  const {
    qty: totalQty,
    price: totalPrice,
    taxAmt,
  } = cart.reduce(
    (acc, result) => {
      acc.qty += result.qty;
      acc.price += result.qty * result.price;
      acc.taxAmt = (result.taxRate / 100) * acc.price;
      return acc;
    },
    { qty: 0, price: 0, taxAmt: 0 }
  );

  const grandTotal = totalPrice + taxAmt + shippingCharge;

  const data = {
    totalQty,
    totalPrice,
    taxAmt,
    grandTotal,
    cart,
  };

  return data;
}

function updateCartDOM(dataObj) {
  badge.textContent = dataObj.totalQty;
  mobileBadge.textContent = dataObj.totalQty;
  cartTotalPrice.textContent = dataObj.totalPrice.toFixed(2) ?? 0.0;
  cartTaxPrice.textContent = dataObj.taxAmt.toFixed(2) ?? 0.0;
  cartShippingCharge.textContent =
    shippingCharge > 0 ? shippingCharge.toFixed(2) : " --- ";
  cartGrandTotal.textContent = dataObj.grandTotal.toFixed(2) ?? 0.0;

  if (dataObj.cart.length == 0) {
    cartTotalPrice.textContent = "0.00";
    cartBody.innerHTML = `
			<tr>
				<td colspan="5" style="text-align: center;">No item in Cart!</td>
			<tr>
		`;

    checOutBtn.disabled = true;

    return;
  }

  checOutBtn.disabled = false;
  cartBody.innerHTML = "";

  dataObj.cart.forEach((el) => {
    const domString = `
      <tr scope="row">
        <td>${el.name}</td>
        <td class="sm-rm">$${el.price}</td>
        <td style="text-align: center;">${el.qty}</td>
        <td>$${el.qty * el.price}</td>
        <td>
          <a onclick="userConfirmation('Do you want to delete this item?', 'removeItem.bind(null, ${
            el.id
          })')" class="btn-delete-item btn btn-danger" title="Remove this item" data-toggle="tooltip" data-id="${
      el.id
    }"> <i class="fa fa-trash" aria-hidden="true"></i> </a> 
          <a onclick="decreaseQty(${
            el.id
          })" class="btn-decrease-item btn btn-success" title="Decrease Item" data-toggle="tooltip" data-id="${
      el.id
    }"> <i class="fa fa-minus" aria-hidden="true"></i> </a>
          <a onclick="addQty(${
            el.id
          })" class="btn-add-item btn btn-success" title="Add Item" data-toggle="tooltip" data-id="${
      el.id
    }"> <i class="fa fa-plus" aria-hidden="true"></i> </a>
        </td>
      </tr>
    `;

    cartBody.insertAdjacentHTML("beforeend", domString);
  });
}

function updateLSWithObj(obj, alert = false, message = "Alert") {
  const addableString = JSON.stringify(obj);
  localStorage.setItem(localStorageName, addableString);
  cartString = addableString;
  updateCartDOM(getCartData());

  if (alert) {
    const alertConfig = {
      title: message,
      icon: "success",
      toast: true,
      position: "bottom-end",
      showConfirmButton: false,
      timer: 2000,
      timerProgressBar: true,
    };

    Swal.fire(alertConfig);
  }
}

class Item {
  constructor(id, name, price, taxRate) {
    this.id = +id;
    this.name = name;
    this.price = +price;
    this.qty = 1;
    this.taxRate = +taxRate;
    this.taxAmt = (this.taxRate / 100) * this.price;
  }

  addItem() {
    cart.push(this);
    updateLSWithObj(cart, true, "Item added to Cart.");
  }
}

const addToCart = (dataObj) => {
  const item = new Item(
    dataObj.id,
    dataObj.name,
    dataObj.price,
    dataObj.taxrate
  );
  item.addItem();
};

function addQty(id) {
  const index = getIndex(id);
  cart[index].qty++;
  updateLSWithObj(cart);
}

function decreaseQty(id) {
  const index = getIndex(id);
  cart[index].qty--;

  if (cart[index].qty === 0) {
    userConfirmation(
      "Do you want to delete this item?",
      `removeItem.bind(null, ${id})`,
      "false"
    );
    return;
  }

  updateLSWithObj(cart);
}

function removeItem(id, openQual = true) {
  if (openQual) {
    close_qual();
  }

  const index = getIndex(id);
  cart.splice(index, 1);
  updateLSWithObj(cart, true, "Item removed from cart.");
}

function clearCart(openQual = true) {
  if (openQual) close_qual();

  cart = [];

  updateLSWithObj(cart, true, "Cart cleared.");
}

cartBtn.forEach((el) => {
  el.addEventListener("click", (el) => {
    const elDataset = el.target.dataset;
    const index = cart.findIndex((el) => el.id === +elDataset.id);
    if (index !== -1) {
      cart[index].qty++;
      updateLSWithObj(cart, true, "Item added to Cart!");
    } else {
      addToCart(elDataset);
    }
  });
});

clearCartBtn.addEventListener("click", () => {
  userConfirmation("Do you want to clear the entire cart?", "clearCart");
});

document.addEventListener("DOMContentLoaded", () => {
  updateLSWithObj(cart);
});

checOutBtn.addEventListener("click", () => {
  showLoader();
  location.href = "billing.php";
});

async function billingRequest(billingData) {
  showLoader();

  const reqUrl = "function/billingHandler.php";

  const requestConfig = {
    method: "POST",
    url: reqUrl,
    data: {
      billingData,
      cart,
    },
  };

  const { data } = await axios(requestConfig);

  if (data.status === 200) {
    hideLoader();
    // do what you want to do if sucess
  } else if (data.data.msg) {
    hideLoader();
    Qual.error(removeTags(data.data.msg), "");
  } else {
    hideLoader();
    Qual.error("Something Went Wrong", "");
  }
}
