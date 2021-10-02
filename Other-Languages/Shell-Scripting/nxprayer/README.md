# Next Prayer (nxprayer)

`Islamic prayers` reminder, for your status bar or/and scripts.

---

## Features
- displays the `next prayer time`.
- `send notification` if it's the time for a prayer.
- displays the `remaining time` till the next prayer.

---

## Usage

```
FLAGS:
  -r,	--remain	display the remaining time till the next prayer.
  -n,	--next		display the time of the next islamic prayer.
  -d,	--adhan		display if it's the time for adhan by returning binary value(0, 1).
  -h,	--help		display this help information.
```

> For more info read the MAN PAGE.

##### Terminal

```
$ nxprayer -n
🕌 Dhuhr 11:47 AM

$ nxprayer -r
05:13
```


##### Status bars:
If you are using [dwmblocks](https://github.com/torrinfail/dwmblocks) or [i3blocks](https://github.com/vivien/i3blocks) you could put `nxprayer` in your `config` file as a script.


##### Screenshot

![np](np.png)

---

## Installation

##### For Arch based systems:

```
yay -S nxprayer
```

##### For other distros:

##### Dependencies
`Install the dependencies first.`

`jq` `python3` `gawk` `gcc` `bash` `libnotify`

And then.

```
git clone https://github.com/AbdeltwabMF/nxprayer.git
cd nxprayer
sudo make clean install
```

---

## [License](LICENSE)

Licensed under the GPL-v3 License.
