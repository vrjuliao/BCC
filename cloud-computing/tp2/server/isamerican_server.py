from datetime import datetime
from flask import Flask, request, jsonify
import pickle
import json
from datetime import date
import os
import os.path

last_update_date = date.min
latest_version = 'v0.0.0'
repository_path = os.path.abspath('')
model = None
# model = pickle.load(open(os.path.join(repository_path,'isamerican.pickle'), 'rb'))



def load_model():
  global last_update_date, latest_version, repository_path, model
  model_metadata = os.environ.get('MODEL_METADATA')
  if model_metadata is not None:
    model_metadata = json.loads(model_metadata)
    year, month, day = tuple(model_metadata.split('-'))
    current_update_date = date.fromisoformat(year, month, day)
    if(current_update_date > last_update_date):
      last_update_date = current_update_date
      latest_version = model_metadata['version']
    else: return 
  else: return
  model = pickle.load(open(os.path.join(repository_path,'isamerican.pickle'), 'rb'))

app = Flask(__name__)
@app.route("/api/american", methods=["POST"])
def api_american():
  global model, last_update_date, latest_version
  load_model()
  if model is None:
    return jsonify({'err': 'no predictor model to load'}), 503

  content = request.json
  print(content)
  is_american = model.predict([content['text']])
  return jsonify({
    "is_american": str(is_american[0]),
    "version": latest_version,
    "model_date": last_update_date.strftime('%Y-%m-%d')
  })
