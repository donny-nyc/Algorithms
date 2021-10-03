def Settings(**kwargs):
    return {
      'flags': [
          '-x',
          'c++',
          '-Wall',
          '-Wextra',
          '-Werror',
          '-I./include',
          '-I./src',
          ],
    }
