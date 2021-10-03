import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import os

engine = pyttsx3.init('sapi5')

voices = engine.getProperty('voices')

engine.setProperty('voice',voices[1 ].id)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning!")
    elif hour>=12 and hour <18:
        speak("Good Aafternoon!")
    else:
        print("Good Evening!")
        speak("Good Evening!")

    print("I am Jarvis Sir. Pleeease tell me how may I help you?")
    speak("I am Jarvis Sir. Pleeease tell me how may I help you?")

def takeCommand():

    r= sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)
     
    try:
        print("Recognizing...")
        query = r.recognize_google(audio,language='en-in')
        print(f"User said: {query}\n")
    
    except Exception as e:

        print("Say that again please...")
        return "None"
    return query


if __name__ == "__main__":
    wishMe()
    while True:
        query= takeCommand().lower()
        
        if 'wikipedia' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences = 2)
            speak("According to Wikipedia")
            print(results)
            speak(results)
        
        elif 'open youtube' in query:
            webbrowser.open("youtube.com")
        elif 'open google' in query:
            webbrowser.open("google.com")
        elif 'open gmail' in query:
            webbrowser.open("gmail.com")
        elif 'open stackoverflow' in query:
            webbrowser.open("stackoverflow.com")
        elif 'open github' in query:
            webbrowser.open("github.com")
        elif 'open instagram' in query:
            webbrowser.open("instagram.com")
        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"Sir, the time is {strTime} ")
            print(strTime)

        elif 'my picture' in query:
            path = "C:\\Users\\XYZ\\Documents\\user.jpg"
            os.startfile(path)
        
        elif 'how are you' in query:
            print("I am fine sir!!")
            speak("I am fine sir")
        
        elif 'do you know me' in query:
            print("Yess, ofcourse sir!!")
            speak("Yess, ofcourse sir!!")
        
        elif 'who am i' in query:
            print("You are XYZ, you created me sir!!")
            speak("You are XYZ you created me sir!!")
        elif 'what is my name' in query:
            print("You are XYZ, you created me sir!!")
            speak("You are  XYZ , you created me sir!!")
        elif 'Thank you' in query:
            exit()