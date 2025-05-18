# Vars
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Executable file names 
SERVER = server
CLIENT = client

# Dirs
SRCDIR = src
OBJDIR = obj

# Dirs of libs
LIBFTDIR = libs/libft
FTPRINTF_DIR = libs/libftprintf

SRC = server.c client.c
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
SRCS = $(addprefix $(SRCDIR)/,$(SRC))

SERVER_OBJ = $(OBJDIR)/server.o
CLIENT_OBJ = $(OBJDIR)/client.o
# Rules of files
all: $(SERVER) $(CLIENT)

# Executable build rules (explicit)
$(SERVER): $(SERVER_OBJ) $(LIBFTDIR)/libft.a $(FTPRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFTDIR) -L$(FTPRINTF_DIR) -lftprintf -lft -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFTDIR)/libft.a $(FTPRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFTDIR) -L$(FTPRINTF_DIR) -lftprintf -lft -o $(CLIENT)

# Build the object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(FTPRINTF_DIR) -c $< -o $@

# Rules to build the libraries
$(LIBFTDIR)/libft.a:
	$(MAKE) -C $(LIBFTDIR)

$(FTPRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(FTPRINTF_DIR)

# Rules of actions

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re