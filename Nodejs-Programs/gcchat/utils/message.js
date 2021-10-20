function formatMessage(message, sender = "admin") {
  return {
    message,
    sender,
  };
}

module.exports = formatMessage;
