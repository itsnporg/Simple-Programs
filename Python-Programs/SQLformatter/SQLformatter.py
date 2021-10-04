import re
import sys

keywords = [
    "select",
    "create",
    "drop",
    "from",
    "where",
    "insert",
    " int",
    " varchar",
    " date",
    "database",
    "table",
    "into",
    "values",
    "group by",
    "desc",
    "order by",
    " float",
    " char",
    " text",
    " number",
    " time",
    " timestamp",
    "delete",
    "if",
    "exists",
    "in",
    "not",
    " datetime",
    "add",
    "constraint",
    "primary key",
    "foreign key",
    "constraints",
    "alter",
    "all",
    "and",
    "any",
    "as",
    "case",
    "when",
    "column",
    "index",
    "between",
    "check",
    "end",
    "when",
    "null",
    "unique",
    "identity",
    "serial",
    "view",
    "default",
    "distinct",
    "exec",
    "extract",
    "having",
    "join",
    "outer",
    "left",
    "inner",
    "right",
    "like",
    "limit",
    "or",
    "procedure",
    "rownum",
    "top",
    "update",
    "set",
    "truncate",
    "union",
    "ascii",
    "char_length",
    "character_length",
    "concat",
    "field",
    "format",
    "cast",
    "replace",
    "locate",
    "ucase",
    "upper",
    "min",
    "max",
    "sum",
    "avg",
    "count",
    "exp",
    "floor",
    "round",
    "adddate",
    "addtime",
    "datediff",
    "current_date",
    "current_time",
    "current_timestamp",
    "sysdate",
    "time_format",
    "to_days",
    "coalesce",
    "convert",
    "current_user",
    "isnull",
    "ifnull",
    "version",
    "or",
    "full join",
    "check",
    "auto",
    "auto_increment",
    "identity",
    " on",
    "disk",
    "bit",
    "with",
    "then",
    "else",
]

uppercase = lambda x: x.group(1).upper()
re_replace = re.compile(r"\b({})\b".format("|".join(keywords)))


def SQLformat(sqlFile):
    try:
        with open(sqlFile) as input_sqlFile:
            content = input_sqlFile.read()

        with open(sqlFile, "w") as output_sqlFile:
            # for word in keywords:
            #    content = content.replace(word.lower(), word.upper())
            # output_sqlFile.write(content)
            output_sqlFile.write(re_replace.sub(uppercase, content.lower()))
            print(
                "\033[1m\033[92m[+] Executed :\033[0m File Changed to correct SQL format!\n\033[1m\033[92m[+] SUCCESS !\033[0m"
            )
    except Exception as e:
        print(
            "\033[1m\033[91m[-] Error:\033[0m",
            e,
            "\n\033[1m\033[91m[-] FAILURE !\033[0m",
        )


if __name__ == "__main__":
    print(
        """\033[1m\033[33m
____ ____ _       ____ ____ ____ _  _ ____ ___ ___ ____ ____ 
[__  |  | |    __ |___ |  | |__/ |\/| |__|  |   |  |___ |__/ 
___] |_\| |___    |    |__| |  \ |  | |  |  |   |  |___ |  \ 

                                               ~ From SAPHAL
           \033[0m """
    )
    try:
        sqlFile = sys.argv[1]
        if ".sql" in sqlFile:
            SQLformat(sqlFile)
        else:
            print(
                "\033[1m\033[91m[-] Error:\033[0m Please select SQL file only!\033[0m\n\033[1m\033[91m[-] FAILURE !\033[0m"
            )
    except Exception as e:
        print(
            "\033[1m\033[91m[-] Error:\033[0m",
            e,
            "\n\033[1m\033[91m[-] FAILURE !\033[0m",
        )
        exit(0)
