# Windows Install

### Prerequisites

* Laptop. You will need a laptop with administrator access. Using a remote service will be possible but not as
convenient.  It should be able to run a recent updated version of the operating system, support the latest
version of Docker, with 8 GB of RAM 512 GB SSD disk space, and 4 cores should be sufficient.
* Docker.  Podman is an open source alternative, but it is not as good.
* Github pro user account.  Students can have pro features by registering here: https://education.github.com/pack
* 1Password.  Not free, but you, your boss and your customers care about your security.
* ChatGPT pro.  There is no comparable tool and the pro version is substantially better than the free version.

1. Whole disk encrypt your drive.  Turn on bitlocker.  Save your recovery with print to pdf, save the pdf to your documents, then save the recovery keys as a record in a secure location (1Password).
2. Install WSL/Ubuntu LTS.  Use the app store to install the latest version of Ubuntu LTS.
    1. The installer should open up a console to create your ubuntu account.  Use a user name with no spaces.
    2. In the console run (this will download perhaps a gigabyte of data and take several minutes to run):
    ```bash
    # update package information
    sudo apt-get update
    
    # upgrade to latest stable versions
    sudo apt-get upgrade -y
    
    # install basic dev tools
    sudo apt-get install -y git git-crypt gnupg build-essential wslu
    ```
    3. Link linux and windows users.  Create some useful symbolic links between your windows and linux user accounts.
    ```bash
    # Symbolic link wsl ~/downloads folder to windows Downloads folder,
    # typically /home/<lin user>/downloads -> /mnt/c/Users/<win user>/Downloads
    ln -s "$(wslpath -u "$(powershell.exe -command "(New-Object -ComObject Shell.Application).NameSpace('shell:Downloads').Self.Path" | tr -d '\r\n')")" "$HOME/downloads"

    # Symbolic link wsl ~/winhome folder to windows user home,
    # typically, /home/<lin user>/winhome -> /mnt/c/Users/<win user>
    ln -s "$(wslpath -u "$(wslvar USERPROFILE)")" "$HOME/winhome"

    # Symbolic link wsl ~/documents folder to windows Documents folder
    # typically, /home/<lin user>/documents -> /mnt/c/Users/<win user>/documents
    ln -s "$(wslpath -u "$(powershell.exe -command "[Environment]::GetFolderPath('MyDocuments')" | tr -d '\r\n')")" "$HOME/documents"
    ```
3. Install Docker Desktop: https://www.docker.com
    1. Do not "run as administrator" this seems to break things later.
    2. Log in using the GUI - I had to reinstall once before this would work.
    3. In the Settings (gearbox) -> Resources make sure you have WSL 2 integration.
    4. Check that your Ubuntu LTS is the default WSL distribution for integration
       with docker. In your WSL shell check with
   ```bash
    # check that This distrubution is the default distribution
    wsl.exe --list
    echo "You should see: $WSL_DISTRO_NAME (Default)"
    ```
    If you don't see your distribution as the default, set it with,
    ```bash
    wsl.exe --set-default "$WSL_DISTRO_NAME"
    ```
    I would restart docker and wsl if you have to set the default.  If it is the
    default, and you have started docker, then you should be able to run the
    docker command from within the container
    ```bash
    # test that docker is running kind of output
    docker run --rm hello-world # output should be Hello from Docker!...
    ```
4. Configure GnuPG
    1. If you already have a GnuPG account, download the tar file from 1Password and extract it into your $HOME/.gnupg directory:
    ```bash
    # assumes you have downloaded your encrypted gnupg file from 1Password to dot-gnupg-tar.enc
    # you will have to provide the password (saved in 1Password/keychain) to decrypt this
    openssl aes-256-cbc -a -d -pbkdf2 -in ~/downloads/gnupg-tgz.enc -out - | tar -C ~ zxvf -
    ```
    2. If you have never configured and saved your private keys
        1. Generate a new public/secret gpg key.  Use defaults (ECC sign & encrypt, Curve25519, forever), your full name, and github email) and password protect your secret keys
        ```bash
        gpg --full-gen-key
        ```
	
        2. Save your public key and encrypted backup to 1Password 
        ```bash
        gpg --armor --export <github email> > ~/downloads/gnupg-pubkey.asc
        tar zcf - .gnupg | openssl aes-256-cbc -a -salt  -pbkdf2 -in - -out ~/downloads/gnupg-tgz.enc
        ```
        Upload the files created (gnupg-pubkey.asc and gnupg-tgz.enc in your windows Downloads directory) to 1Password.
5. Make SSH keys if you have not already (no password - your drive is encrypted and its only for this laptop):
```bash
test -f ~/.ssh/id_rsa || ssh-keygen
```

6. Export the SSH public key to Github.  You can copy the public key to the clipboard with
```bash
cat ~/.ssh/id_rsa.pub | clip.exe
```
Log into github, and in the hidden menu under your avatar, you can go to settings and "ssh/gpg keys" and paste in the new key.
7. Configure `git`.  Use your real name and email you registered on GitHub:
```bash
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```
8. Clone this repository.  You will have less trouble if you live in the WSL directory namespace:
```bash
mkdir -p ~/projects
cd ~/projects
git clone git@github.com:rambasnet/course-container
```
9. Run some tests
```bash
. "$(git rev-parse --show-toplevel)/ops/setup"
ops test-ops
ops cloudbox --build --test # this downloads a lot and takes several minutes to get an "ok"
```
