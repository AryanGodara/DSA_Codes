SCHEMATHESIS_TOKEN=EbYYXnQapYA8p6XLVApoR4Reum0sxl


```
jobs:
api-tests:
  runs-on: ubuntu-20.04
  # Your app could be written in any language
  # This is a sample Python app
  steps:
    # Gets a copy of the source code in your repository before running API tests
    - uses: actions/checkout@v3.0.0

    - uses: actions/setup-python@v4
      with:
        python-version: '3.10'

    # Installs project's dependencies
    - run: pip install -r requirements.txt

    # Start the API in the background
    - run: python main.py &

    # Runs Schemathesis tests
    - uses: schemathesis/action@v1
      with:
        # Your API schema location
        schema: 'http://localhost:5000/api/openapi.json'
        # Set your token from secrets
        token: ${{ secrets.SCHEMATHESIS_TOKEN }}
```
