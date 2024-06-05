NAME := $(patsubst %, lib%.a, $(notdir $(shell pwd)))
SUBDIRS = $(notdir $(shell find . -type d -maxdepth 1 -not -name "." -not -path "./.*" | sort))

LIBS := $(foreach DIR, $(SUBDIRS), $(addsuffix /$(patsubst %,lib%.a, $(notdir $(DIR))), $(DIR)))

.PHONY: all clean fclean re $(SUBDIRS)

all: $(NAME)

$(NAME): $(LIBS)
	@echo "Compiling $@ from sub-libraries..."
	@libtool -static -o $@ $^
	@echo "Done!"

$(LIBS): $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@ $(MAKECMDGOALS)

clean: $(SUBDIRS)

fclean: $(SUBDIRS)
	@echo "Fully cleaning $(NAME)..."
	@rm -vf $(NAME)
	@echo "Done!"

re: fclean all
