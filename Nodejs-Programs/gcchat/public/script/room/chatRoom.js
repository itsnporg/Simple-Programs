const username = localStorage.getItem("username");
const messageInboxElement = document.querySelector("#message-inbox");

// check if username store on storage or not
if (!username) redirectToHomepage();

socket.emit("new-user", { username, roomName });

socket.on("welcome-user", (data) => {
  displayMessage(data);
});

socket.on("new-user-joined", (data) => {
  displayMessage(data);
});

// message send handler

const messageBoxElement = document.querySelector("#message-box");
const sendMsgBtnElement = document.querySelector("#send-message-btn");

sendMsgBtnElement.addEventListener("click", messageSendHandler);

socket.on("chat-message", (data) => {
  displayMessage(data);
});

socket.on("user-left", (data) => {
  displayMessage(data);
});

function redirectToHomepage() {
  window.location.href = "/root";
  return;
}

function displayMessage(data) {
  const messageWrapperElement = createMessageWrapperElement(data);
  messageInboxElement.appendChild(messageWrapperElement);
}

function createMessageWrapperElement(data) {
  const messageWrapperElement = document.createElement("div");
  messageWrapperElement.id = "message-wrapper";

  const messageWrapperChildren = createMsgWrapperChildren(data);
  messageWrapperElement.append(messageWrapperChildren);

  return messageWrapperElement;
}

function createMsgWrapperChildren({ message, sender }) {
  const messageWrapperChildren = document.createDocumentFragment();

  messageWrapperChildren.appendChild(createSenderNameElement(sender));
  messageWrapperChildren.appendChild(createMessageElement(message));

  return messageWrapperChildren;
}

function createSenderNameElement(sender) {
  const senderNameElement = document.createElement("span");
  senderNameElement.id = "sender-name";
  senderNameElement.textContent = `${sender}: `;

  return senderNameElement;
}

function createMessageElement(message) {
  const messageElement = document.createElement("span");
  messageElement.id = "sender-message";
  messageElement.textContent = message;

  return messageElement;
}

function messageSendHandler(event) {
  const messageBoxValue = messageBoxElement.value;

  if (!messageBoxValue) {
    alert("type your message");
    return;
  }

  displayMessage({ message: messageBoxValue, sender: "you" });
  socket.emit("new-message", messageBoxValue);
  messageBoxElement.value = "";
}
