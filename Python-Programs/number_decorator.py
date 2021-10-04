# to decorate country code according to user defined countrycode
# the best practical way to learn python decorator
country_code = {"nepal": 977, "india": 91, "us": 1}


def formatted_mob(original_func):
    def wrapper(country, num):
        country = country.lower()
        if country in country_code:
            return f"+{country_code[country]}-{original_func(country,num)}"
        else:
            return num

    return wrapper


@formatted_mob
def num(country, num):
    return num


number = num("nepal", 9844718578)
print(number)
