import json

from flask import Flask, Blueprint, request

from .controller import BiorobotController


def create_app():
    app = Flask(__name__)
    bp = create_api_routes()
    app.register_blueprint(bp)
    return app


def create_api_routes():
    bp = Blueprint('biorobot_api', __name__, url_prefix='/api')
    controller = BiorobotController()

    @bp.route('/beverage', methods=['POST'])
    def register_beverage():
        data = request.form
        username = data.get('user_name')
        beverage = data.get('text') or 'bionade'
        controller.register_event(username, beverage)
        return 'Beverage request logged.'

    @bp.route('/query', methods=['GET'])
    def query():
        if not controller.events:
            return None
        else:
            res = controller.events[0]
        return json.dumps(res)

    @bp.route('/status', methods=['POST'])
    def update_status():
        data = request.json
        status = data.get('status', 'pending')
        uid = data.get('uid')
        controller.changing_status(uid, status)
        return 'Status updated'

    return bp
