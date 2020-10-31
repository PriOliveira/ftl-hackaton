#!/bin/sh

gunicorn --chdir app \
  --workers 1 \
  --threads 4 \
  --worker-connections 200 \
  --max-requests 500 \
  --max-requests-jitter 20 \
  -b 0.0.0.0:80 \
  --access-logfile - \
  --limit-request-line 150 \
  --limit-request-field_size 200 \
  app
