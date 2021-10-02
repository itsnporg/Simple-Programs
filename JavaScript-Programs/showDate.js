// JavaScript function to show the date

function showDate() {
	const d = new Date();
	document.getElementById("date-p").innerHTML = d; // For this code to work, you need to keep the paragraph tag's id as "date-p" and you need to keep "onClick=showDate();" in the button's tag
}
