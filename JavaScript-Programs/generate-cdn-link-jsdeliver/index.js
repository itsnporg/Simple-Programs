// Convert github file into jsdeliver cdn link, with or without minify
// Supported file: Javascript and CSS

const getCDNLink = (link, isMinify = false) => {
	const linkParts = link.split("/")
	const isGithubLink = linkParts.includes("github.com")
	const indexOfGithub = linkParts.indexOf("github.com")

	// check the link is related github or not
	if (!isGithubLink) return console.log("This is not Github link.")

	let fileName = linkParts[linkParts.length - 1]

	// get the extension name
	let checkExtension = fileName.split(".")[1]

	// check the extension of javascript or css if not then throw error
	if (!(checkExtension === "js" || checkExtension === "css"))
		return "Not supported file. Make sure must be CSS or JavaScript"

	const githubAccount = linkParts[indexOfGithub + 1]
	const repoName = linkParts[indexOfGithub + 2]
	const branchType = linkParts[indexOfGithub + 4]
	const directoryPath = linkParts
		.slice(indexOfGithub + 5, linkParts.length - 1)
		.toString()
		.replace(/,/g, "/")

	// if isMinify is true then change the file to compressed file
	if (isMinify) {
		fileName = fileName.replace(/\./, ".min.")
	}

	// concat all the parts and generate the link and return it
	return `https://cdn.jsdelivr.net/gh/${githubAccount}/${repoName}@${branchType}/${directoryPath}/${fileName}`
}

export default getCDNLink
