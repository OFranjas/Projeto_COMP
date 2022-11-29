# Create a zip file of the current directory
# Usage: create_zip.sh <zipfile>
# Example: create_zip.sh myzip.zip

# Check for the zip file name
if [ $# -eq 0 ]
then
    echo "Usage: create_zip.sh <zipfile>"
    exit 1
fi

# Create the zip file for file jucompiler.l and expr.y
zip $1 jucompiler.l expr.y analise_semantica.c analise_semantica.h lex.yy.c y.tab.c y.tab.h Tree.c Tree.h

