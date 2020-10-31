FROM python:3.7.3-slim

COPY requirements.txt /
RUN pip3 install -r /requirements.txt && rm /requirements.txt

RUN mkdir -p /app

COPY start.sh /
COPY app.py /app
COPY biorobot_server /app/biorobot_server

CMD ["/start.sh"]
