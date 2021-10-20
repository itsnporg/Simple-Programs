# Animal Game

This is a console-based 'animal guessing game'. Here's an example of the input and output of the program which I used during testing:

```
Computer: Think of an animal
Computer: Is it a duck? (yes/no)
Human:    no
Computer: Oops - looks like I need to improve.
Computer: What is the animal?
Human:    Monkey
Computer: What question would distinguish between a duck and a monkey?
Human:    Can it fly?
Computer: For a monkey, is the answer "yes" or "no"?
Human:    no
Computer: Thanks for helping me to improve!

Computer: Want to play again? (yes/no)
Human:    yes

Computer: Think of an animal
Computer: Can it fly? (yes/no)
Human:    yes
Computer: Is it a duck? (yes/no)
Human:    no
Computer: Oops - looks like I need to improve.
Computer: What is the animal?
Human:    Parrot
Computer: What question would distinguish between a duck and a parrot?
Human:    Can it swim?
Computer: For a parrot, is the answer "yes" or "no"?
Human:    no
Computer: Thanks for helping me to improve!

Computer: Want to play again? (yes/no)
Human:    yes
Computer: Think of an animal
Computer: Can it fly? (yes/no)
Human:    no
Computer: Is it a monkey? (yes/no)
Human:    yes
Computer: Yay!  I got it!

Computer: Want to play again? (yes/no)
Human:    yes
Computer: Think of an animal
Computer: Can it fly? (yes/no)
Human:    no
Computer: Is it a monkey? (yes/no)
Human:    no
Computer: Oops - looks like I need to improve.
Computer: What is the animal?
Human:    Dog
Computer: What question would distinguish between A monkey and a dog?
Human:    Can it climb trees?
Computer: For Dog, is the answer "yes" or "no"?
Human:    no
Computer: Thanks for helping me to improve!

Computer: Want to play again? (yes/no)
Human:    yes
Computer: Think of an animal
Computer: Can it fly? (yes/no)
Human:    no
Computer: Can it climb trees? (yes/no)
Human:    no
Computer: Is it Dog? (yes/no)
Human:    no
Computer: Oops - looks like I need to improve.
Computer: What is the animal?
Human:    Cow
Computer: What question would distinguish between a dog and a cow?
Human:    Is it taller than 1 meter?
Computer: For a cow, is the answer "yes" or "no"?
Human:    yes
Computer: Thanks for helping me to improve!

Computer: Want to play again? (yes/no)
Human:    yes
Computer: Think of an animal
Computer: Can it fly? (yes/no)
Human:    no
Computer: Can it climb trees? (yes/no)
Human:    yes
Computer: Is it a monkey? (yes/no)
Human:    no
Computer: Oops - looks like I need to improve.
Computer: What is the animal?
Human:    Cat
Computer: What question would distinguish between a monkey and a cat?
Human:    Is it a pet?
Computer: For a cat, is the answer "yes" or "no"?
Human:    yes
Computer: Thanks for helping me to improve!

Computer: Want to play again? (yes/no)
Human:    no

(program exits)
```

## Get Started

Run the following commands:

`npm init`
`npm install`
`npm install readline-sync --save`

<hr>
If you want to test the program, first delete the tree.data_json file and I suggest you comment out these code in main.js file:

`const rawData = fs.readFileSync("./tree_data.json");`
`const json = JSON.parse(rawData);`
`if (Object.entries(json).length !== 0) root = json;`

`const data = JSON.stringify(root);`
`console.log("\n" + data);`
`fs.writeFile("tree_data.json", data, (err) => {`
`if (err) throw err;`
`console.log("\nJSON data is saved.");`
`});`

<hr>
#####Note:
If you want to save your input choices to a json file and use it next time when you run the program, store it in a JSON file first and then recall the JSON file.
Both done in the above snippets.
