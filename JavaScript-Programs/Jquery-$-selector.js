// This gives us a Jquery like  selector function.
// Now we can select any element in out document like this $(".class") , or  $("#id") , or $("tagname")
// We won't have to keep doing document.getElementById or document.querySelector
// This makes it easy for us to select elements in out HTML document.

const $ = (selector = "") => {
  selector = selector.toString();
  return !selector
    ? []
    : selector[0] === "#"
    ? document.querySelector(selector)
    : document.querySelectorAll(selector).length === 1
    ? document.querySelectorAll(selector)[0]
    : document.querySelectorAll(selector);
};

// Now we can do like this

const divs = $("div");
const textArea = $("#textArea");
const links = $(".links");
