#!/bin/bash
read -p "Commit Description: " desc
git add .
git commit -m "$desc"
git push origin master
