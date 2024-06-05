NAME = $(patsubst %, lib%.a, $(notdir $(shell pwd)))

SRCS = $(shell find $(SDIR) -name "*.c")
OBJS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

ifndef SDIR
	SDIR = srcs
endif
ifndef ODIR
	ODIR = objs
endif
ifndef HDIR
	HDIR = ..
endif
ifndef CC
	CC = cc
endif
ifndef CFLAGS
	CFLAGS = -Wall -Wextra -Werror
endif

HDIR += headers

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating library $@ from objects..."
	@ar -rcs $@ $^
	@echo "Done!"

$(ODIR)/%.o: $(SDIR)/%.c
	@echo "Compiling $(<F) to object..."
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(addprefix -I, $(HDIR)) -o $@ -c $<

clean:
	@echo "Cleaning $(NAME)..."
	@rm -fv $(OBJS)
	@echo "Done!"

fclean:
	@echo "Fully cleaning $(NAME)..."
	@rm -fv $(OBJS) $(NAME)
	@echo "Done!"

re: fclean all
