:- multifile 
      user:file_search_path/2.

user:file_search_path(database, './db').
user:file_search_path(css, './dir_css').
user:file_search_path(schemas, database(schemas)).
user:file_search_path(tables, database(tables)).