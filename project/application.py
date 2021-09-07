# I had done this below project when I was doing a JavaScript course from udemy after completeing the Harvard cs50's course

import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# # Configure CS50 Library to use SQLite database
# db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        return render_template("game.html")
    else:
        # To display the entrance of the game.
        return render_template("index.html")


