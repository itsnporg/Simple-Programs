"""
File: searchengine.py
---------------------
This is a text based version of a search engine , which when provided directory name for the dataset
will enable us to run the search engine and provide results for our search queries from that dataset :)
"""


import os
import string
import sys


def create_index(filenames, index, file_titles):
    """
    This function is passed:
        filenames:      a list of file names (strings)
        index:          a dictionary mapping from terms to file names (i.e., inverted index)
                        (term -> list of file names that contain that term)
        file_titles:    a dictionary mapping from a file names to the title of the article
                        in a given file
                        (file name -> title of article in that file)
    The function will update the index passed in to include the terms in the files
    in the list filenames.  Also, the file_titles dictionary will be updated to
    include files in the list of filenames.
    """
    filenames = list(set(filenames))
    filenames.sort()
    for file in filenames:
        with open(file) as f:
            for lines in f:
                lines = lines.strip().split()
                for terms in lines:
                    terms = terms.strip(string.punctuation).lower()
                    if terms != "":
                        if terms not in index:
                            index[terms] = [file]
                        else:
                            file_list = index[terms]
                            file_list.append(file)
        with open(file) as f:
            line_temp = f.readlines()
            title = line_temp[0].strip()
            file_titles[file] = title


def search(index, query):
    """
    This function is passed:
        index:      a dictionary mapping from terms to file names (inverted index)
                    (term -> list of file names that contain that term)
        query  :    a query (string), where any letters will be lowercase
    The function returns a list of the names of all the files that contain *all* of the
    terms in the query (using the index passed in).
    """
    posting_ls = []
    query_ls = query.strip().split()
    if query_ls[0] in index:
        posting_ls = index[query_ls[0]]
        for terms in query_ls:
            if terms in index:
                new_ls = index[terms]
                posting_ls = common(posting_ls, new_ls)
            else:
                posting_ls = []
                break
    return posting_ls


def common(list1, list2):
    """
    This function is passed two lists and returns a new list containing
    those elements that appear in both of the lists passed in.
    """
    common_list = []
    temp_list = list1.copy()
    temp_list.extend(list2)
    temp_list = list(set(temp_list))
    temp_list.sort()
    for i in temp_list:
        if (i in list1) and (i in list2):
            common_list.append(i)
    return common_list


def do_searches(index, file_titles):
    """
    This function is given an inverted index and a dictionary mapping from
    file names to the titles of articles in those files.  It allows the user
    to run searches against the data in that index.
    """
    while True:
        query = input("Query (empty query to stop): ")
        query = query.lower()  # convert query to lowercase
        if query == "":
            break
        results = search(index, query)

        # display query results
        print("Results for query '" + query + "':")
        if results:  # check for non-empty results list
            for i in range(len(results)):
                title = file_titles[results[i]]
                print(str(i + 1) + ".  Title: " + title + ",  File: " + results[i])
        else:
            print("No results match that query.")


def textfiles_in_dir(directory):
    """
    Given the name of a valid directory, returns a list of the .txt
    file names within it.
    Input:
        directory (string): name of directory
    Returns:
        list of (string) names of .txt files in directory
    """
    filenames = []

    for filename in os.listdir(directory):
        if filename.endswith(".txt"):
            filenames.append(os.path.join(directory, filename))

    return filenames


def main():
    """
    Usage: searchengine.py <file directory> -s
    The first argument specified should be the directory of text files that
    will be indexed/searched.  If the parameter -s is provided, then the
    user can interactively search (using the index).  Otherwise (if -s is
    not included), the index and the dictionary mapping file names to article
    titles are just printed on the console.
    """
    # Get command line arguments
    args = sys.argv[1:]

    num_args = len(args)
    if num_args < 1 or num_args > 2:
        print("Please specify directory of files to index as first argument.")
        print(
            "Add -s to also search (otherwise, index and file titles will just be printed)."
        )
    else:
        # args[0] should be the folder containing all the files to index/search.
        directory = args[0]
        if os.path.exists(directory):
            # Build index from files in the given directory
            files = textfiles_in_dir(directory)
            index = {}  # index is empty to start
            file_titles = (
                {}
            )  # mapping of file names to article titles is empty to start
            create_index(files, index, file_titles)

            # Either allow the user to search using the index, or just print the index
            if num_args == 2 and args[1] == "-s":
                do_searches(index, file_titles)
            else:
                print("Index:")
                print(index)
                print("File names -> document titles:")
                print(file_titles)
        else:
            print('Directory "' + directory + '" does not exist.')


if __name__ == "__main__":
    main()
