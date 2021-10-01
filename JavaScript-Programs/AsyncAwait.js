const githubUsers = async () => {
	let response = await fetch(`https://api.github.com/users`);
	let user = await response.json();

	return user;
};

githubUsers();
