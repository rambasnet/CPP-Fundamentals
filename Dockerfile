FROM ubuntu:22.04

RUN apt update \
  && apt install -y \
  build-essential sqlite3 time curl git nano dos2unix \
  net-tools iputils-ping iproute2 sudo gdb less \
  wget bzip2 ca-certificates \
  && apt clean && \
  rm -rf /var/lib/apt/lists/*

ARG USER=user
ARG UID=1000
ARG GID=1000

# Set environment variables
ENV USER=${USER}
ENV HOME=/home/${USER}

# Create user and setup permissions on /etc/sudoers
RUN useradd -m -s /bin/bash -N -u $UID $USER && \
  echo "${USER} ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers && \
  chmod 0440 /etc/sudoers && \
  chmod g+w /etc/passwd 

USER user

WORKDIR ${HOME}

# Set environment variables for Miniconda installation path
ENV CONDA_DIR=/opt/conda
ENV PATH=$CONDA_DIR/bin:$PATH

# Create a Conda environment from an environment.yml file
# Download and install Miniconda
RUN wget --quiet https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O miniconda.sh && \
  /bin/bash miniconda.sh -b -p $CONDA_DIR && \
  rm miniconda.sh

COPY environment.yml ./
COPY requirements.txt ./
RUN conda env create -f environment.yml

# Install zsh - use "Bira" theme with some customization. 
RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.5/zsh-in-docker.sh)" -- \
  -t bira \
  -p git \
  -p ssh-agent \
  -p https://github.com/zsh-users/zsh-autosuggestions \
  -p https://github.com/zsh-users/zsh-completions

RUN conda init bash
RUN conda init zsh
RUN echo "conda init zsh\nconda activate cpp" >> ~/.zshrc

ENV PATH="${HOME}/.local/bin:$PATH"
