# Reverse the reverser

## Building
Run:
```bash
sh build.sh
```

## Usage 
```bash
reverse_reverser [option] <msg>

Options:
  -o            converts orginal to reverse
  -r            converts reverse to orginal
````

## Example
Encrypt message:
```bash
reverse_reverser -o "Hello World!!"
```
output: **!t=EKH0sHEE>!**

Decrypt message:
```bash
reverse_reverser -r "!t=EKH0sHEE>!"
```
Output: **Hello World!!**


