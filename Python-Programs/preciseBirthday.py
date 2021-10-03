from datetime import datetime
from math import floor

# Enter your birthday here.
# Year, month, day, hour*, minute*, second*, ms*
# * optional
DOB = datetime(2000, 1, 1)

# Returns the exact number of seconds, years, days, etc. since your birthdate
# secondsPassed, yearsPassed, etc. are individual counts - they do not go together
# years, days, etc. go together into one count
def calcTimeLived(DOB):
	timePassed		= datetime.utcnow() - DOB
	
	secondsPassed	= timePassed.total_seconds()
	yearsPassed		= secondsPassed / (60 * 60 * 24 * 365)
	daysPassed		= secondsPassed / (60 * 60 * 24)
	hoursPassed		= secondsPassed / (60 * 60)
	minutesPassed	= secondsPassed / (60)

	years	= floor(yearsPassed)
	days	= floor(daysPassed - (years * 365))
	hours	= floor(hoursPassed - (daysPassed * 24))
	minutes	= floor(minutesPassed - (hoursPassed * 60))
	seconds = floor(secondsPassed - (minutesPassed * 60))

	return {
		'secondsPassed'	: secondsPassed,
		'yearsPassed'	: yearsPassed,
		'daysPassed'	: daysPassed,
		'hoursPassed'	: hoursPassed,
		'minutesPassed'	: minutesPassed,
		'years'	: years,
		'days'	: days,
		'hours'	: hours,
		'minutes'	: minutes,
		'seconds' : seconds
	}