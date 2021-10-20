# This program takes a string and gives a verdict
# if the string has positive, neutral or negative impact. 

# The code is used using vader to install the library
# pip install vaderSentiment

# import SentimentIntensityAnalyzer class
# from vaderSentiment.vaderSentiment module.
from vaderSentiment.vaderSentiment import SentimentIntensityAnalyzer


# function to print sentiments
# of the sentence.
def sentiment_scores(sentence):

	# Create a SentimentIntensityAnalyzer object.
	sid_obj = SentimentIntensityAnalyzer()

	# polarity_scores method of SentimentIntensityAnalyzer
	# object gives a sentiment dictionary.
	# which contains pos, neg, neu, and compound scores.
	sentiment_dict = sid_obj.polarity_scores(sentence)
	
	print("Overall sentiment dictionary is : ", sentiment_dict)
	print("sentence was rated as ", sentiment_dict['neg']*100, "% Negative")
	print("sentence was rated as ", sentiment_dict['neu']*100, "% Neutral")
	print("sentence was rated as ", sentiment_dict['pos']*100, "% Positive")

	print("Sentence Overall Rated As", end = " ")

	# decide sentiment as positive, negative and neutral
	if sentiment_dict['compound'] >= 0.05 :
		print("Positive")

	elif sentiment_dict['compound'] <= - 0.05 :
		print("Negative")

	else :
		print("Neutral")



# Driver code
if __name__ == "__main__" :

	print("\n1st statement :")
	sentence = "Geeks For Geeks is the best portal for \
				the computer science engineering students."

	# function calling
	sentiment_scores(sentence)

	print("\n2nd Statement :")
	sentence = "study is going on as usual"
	sentiment_scores(sentence)

	print("\n3rd Statement :")
	sentence = "I am vey sad today."
	sentiment_scores(sentence)

        S=input() 
        sentiment_scores(S) 
