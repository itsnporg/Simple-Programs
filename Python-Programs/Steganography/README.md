# Steganography

Steganography is the technique of hiding secret data within an ordinary, non-secret, file or message in order to avoid detection;
the secret data is then extracted at its destination. Here, we hide text inside image.

## Install dependencies:

```
pip install -r requirements.txt
```

## Commands:

### 1. Hiding/Encoding text in image:

```
python steg.py -e <IMAGE PATH>
```

<img src = 'Assets/encode.png' width=80%>

---

### 2. Retriving message from image:

```
python steg.py -d <ENCODED IMAGE PATH>
```

<img src = 'Assets/decode.png' width=80%>
