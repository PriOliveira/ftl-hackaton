from time import time
from .config import TTL
import uuid


class BiorobotController(object):
    def __init__(self):
        self.events = list()
        self.served = 0
        self.missed = 0

    def register_event(self, username, beverage, ttl=TTL):
        now = time()
        number_of_events = len(self.events)
        self.events = [e for e in self.events if e['end_of_life'] > now]
        if len(self.events) != number_of_events:
            self.missed += number_of_events - len(self.events)
        uid = str(uuid.uuid4())
        self.events.append({
            'user': username,
            'beverage': beverage,
            'uid': uid,
            'status': 'pending',
            'end_of_life': now + ttl,
            'created_at': now,
        })

    def changing_status(self, uid, status):
        if status == 'ongoing':
            for event in self.events:
                if event['uid'] == uid:
                    event['status'] = status
        elif status == 'served':
            for i, event in enumerate(self.events):
                if event['uid'] == uid:
                    self.events.pop(i)
                    self.served += 1
