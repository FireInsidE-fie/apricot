#ifndef APRICOT_H
# define APRICOT_H

# ifdef _WIN32
#  include <SDL/SDL.h> /* Windows specific SDL2 lib */
# else
#  include <SDL2/SDL.h> /* macOS and GNU/Linux-specific lib */
# endif

#endif
