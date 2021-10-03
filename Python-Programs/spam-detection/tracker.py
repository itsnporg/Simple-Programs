import pandas as pd
import streamlit as st
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split

hide_streamlit_style = """
            <style>
            #MainMenu {visibility: hidden;}
            footer {visibility: hidden;}
            </style>
            
            """
st.markdown(hide_streamlit_style, unsafe_allow_html=True)
df = pd.read_csv("spam.csv", skiprows=2, names=["Label", "EmailText"])
df.head(10)

df.groupby("Label").describe()


df["spam"] = df["Label"].apply(lambda x: 1 if x == "spam" else 0)
# df.head()


X_train, X_test, y_train, y_test = train_test_split(
    df["EmailText"], df["spam"], test_size=0.25
)


v = CountVectorizer()
X_train_count = v.fit_transform(X_train.values)
a = X_train_count.toarray()[:3]
X_test_count = v.transform(X_test)
print(a)

from sklearn.naive_bayes import MultinomialNB

model = MultinomialNB()

model.fit(X_train_count, y_train)
percentage = "{:.0%}".format(model.score(X_test_count, y_test))
# WEB PAGE
st.title("\t Spam or Not Spam  detector \n")
emails = st.text_area("Enter a sentence =  ")

if st.button("Predict"):
    emails_count = v.transform([emails])
    result = model.predict(emails_count)
    if result == 1:
        st.header("This is a spam, which is " + str(percentage) + " sure")
    elif result == 0:
        st.header("This is not a spam, which is " + str(percentage) + " sure")
    else:
        st.write("Please write the text.")
