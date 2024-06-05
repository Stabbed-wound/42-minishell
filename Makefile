NAME := minishell

export CC := cc
export CFLAGS := -Wall -Wextra -Werror -g

LIBFT := libft/libft.a

SDIR := srcs
HDIR := headers
ODIR := objs

SRCS := $(shell find $(SDIR) -type f -name "*.c")
OBJS := $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRCS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -L $(dir $(LIBFT)) -l $(patsubst lib%.a,%,$(notdir $(LIBFT))) $(OBJS) -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(HDIR) -I$(dir $(LIBFT)) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(dir $@)

clean:
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@rm -rvf $(ODIR)
	@rm -vf $(NAME).dYSM

fclean:
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@rm -rvf $(ODIR)
	@rm -vf $(NAME).dYSM
	@rm -vf $(NAME)

re: fclean
	@$(MAKE) all
