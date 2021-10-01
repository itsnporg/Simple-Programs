# Cringe Word

It's a basic game where a word (with shuffled letters) will be given and you have guess what it is.

## Building from source

You need a rust compiler to build this project. Visit [here for installation guide](https://www.rust-lang.org/tools/install)
Once you installed the compiler follow the below steps to compile and run the project.

- clone this repo
  ```bash
  git clone https://github.com/itsnporg/Hacktoberfest-2021
  cd Hacktoberfest-2021/Rust-Programs/cringe_word_rem
  ```

## For Linux Users

- place the `words_data.txt` file on your _HOME_ dir.
  ```bash
  cp/mv words_data.txt $HOME
  ```
  It's important to have the same name.

## For Windows Users

Run the program from original project directory.

- Finally compile and run
  ```bash
  cargo build --release
  cargo run
  ```
