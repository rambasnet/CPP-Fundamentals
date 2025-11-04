# MacOS Install

### Prerequisites

* Laptop. You will need a laptop with administrator access. Using a remote service will be possible but not as
convenient.  It should be able to run a recent updated version of the operating system, support the latest
version of Docker, with 8 GB of RAM 512 GB SSD disk space, and 4 cores should be sufficient.
* Docker.  Podman is an open source alternative, but it is not as good.
* Github pro user account.  Students can have pro features by registering here: https://education.github.com/pack
* 1Password.  Not free, but you, your boss and your customers care about your security.

* ChatGPT pro.  There is no comparable tool and the pro version is substantially better than he free version.
* XCode.  Homebrew (next) uses xcode under the hood.
* Homebrew. Open source package manager for MacOS.

1. Whole disk encrypt your drive.  Turn on FileValt.  Save your recovery keys to 1Password.
2. Install Homebrew.  Follow directions about installing XCode if needed.  In a terminal install basic tools
```bash
brew install gnupg openssl git-crypt
```
3. Install Docker Desktop: https://www.docker.com
    1. Do not "run as administrator" this seems to break things later.
    2. Log in using the GUI - I had to reinstall once before this would work.
    3. Test that it works in a terminal:
    ```bash
    # test that docker is running - should produce a 'Hello from Docker!' kind of output
    docker run --rm hello-world
    ```
4. Configure GnuPG
    1. If you already have a GnuPG account, download the tar file from Lastpass and extract it into your $HOME/.gnupg directory:
    ```bash
    # assumes you have downloaded your encrypted gnupg file from 1Password to dot-gnupg-tar.enc
    # you will have to provide the password (saved in 1Password) to decrypt this
    openssl aes-256-cbc -a -d -pbkdf2 -in ~/downloads/gnupg-tgz.enc -out - | tar -C ~ zxvf -
    ```
    2. If you have never configured and saved your private keys
        1. Generate a new public/secret gpg key.  Use defaults (ECC sign & encrypt, Curve25519, forever), your full name, and github email) and password protect your secret keys
        ```bash
        gpg --full-gen-key
        ```
	
        2. Save your public key and encrypted backup to Lastpass 
        ```bash
        gpg --armor --export <github email> > ~/downloads/gnupg-pubkey.asc
        tar zcf - .gnupg | openssl aes-256-cbc -a -salt  -pbkdf2 -in - -out ~/downloads/gnupg-tgz.enc
        ```
        Upload the files created (gnupg-pubkey.asc and gnupg-tgz.enc in your windows Downloads directory) to LastPass.
5. Make SSH keys if you have not already (no password - your drive is encrypted and its only for this laptop):
```bash
test -f ~/.ssh/id_rsa || ssh-keygen
```

6. Export the SSH public key to Github.  You can copy the public key to the clipboard with
```bash
cat ~/.ssh/id_rsa.pub | pbcopy
```
Log into github, and in the hidden menu under your avatar, you can go to settings and "ssh/gpg keys" and paste in the new key.
7. Configure `git`.  Use your real name and email you registered on GitHub:
```bash
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```
8. Clone this repository.  You will have less trouble if you live in the WSL directory namespace:
```bash
cd # change to your WSL home directory
mkdir projects
cd projects
git clone git@github.com:rambasnet/course-container
```
9. Run some tests
```bash
. "$(git rev-parse --show-toplevel)/ops/setup"
ops test-ops
ops cloudbox --build --test # this downloads a lot and takes several minutes to get an "ok"
```


