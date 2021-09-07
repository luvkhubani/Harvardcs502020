import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        name = request.form.get("name")
        if not name:
            return render_template("error.html", message="Missing name")

        month = request.form.get("month")
        if not month:
            return render_template("error.html", message="Missing month")

        day = request.form.get("day")
        if not day:
            return render_template("error.html", message="Missing day")

        db.execute("insert into birthdays(name, month , day) values(?,?,?)",name,month,day)
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("select * from birthdays")
        return render_template("index.html", birthdays = birthdays)


