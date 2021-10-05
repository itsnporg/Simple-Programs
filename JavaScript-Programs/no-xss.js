function sanitize(string) {
	const reservedWords = {
		'&': '&amp;',
		'<': '&lt;',
		'>': '&gt;',
		'"': '&quot;',
		"'": '&#x27;',
		"/": '&#x2F;',
	};
	const reg = /[&<>"'/]/ig;
	return string.replace(reg, (match) => (reservedWords[match]));
}
// &lt;img src=&quot;&quot; onerror=&quot;window.alert(&#x27;fon&#x27;)&quot;&gt;:
console.log(sanitize(`<img src="" onerror="window.alert('fon')">`)); 
