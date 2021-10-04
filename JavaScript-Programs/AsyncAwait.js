const gitHubUser = async () => {
  try {
    const response = await fetch(`https://api.github.com/users`);
    const user = await response.json();

    return user;
  } catch (err) {
    console.log(err);
  }
};
gitHubUser();
