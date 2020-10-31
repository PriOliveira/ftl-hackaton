# Server

The server receives requests from users in Mattermost

## Dependencies

- Docker
- Python 3.7+
- Virtualenv
- Make

## Setup

To install the dependencies, from the project's root folder, run:

```bash
cd server

# Create a virtual environment and activate it
virtualenv env -p python3
source env/bin/activate

# Install dependencies
pip install -r requirements.txt
```

## Running

### Locally

To initialize the server locally, from the project's root folder, use:

```bash
cd server

python app.py
```

### Production

To run it for production, use the docker image.

Enter the server folder, from the project's root folder, use:

```bash
cd server
```

Build the image, specifying values for `IMAGE_NAME` and `IMAGE_TAG` environment variables, with:

```bash
IMAGE_NAME=bionade-robot IMAGE_TAG=alpha make build
```


