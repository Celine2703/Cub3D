NAME		=	cub3D

DIR_SRC		=	srcs/

DIR_OBJ		=	srcs/objs/

LIB_DIR		=	./Libft

MLX_DIR		=	./minilibx-linux

MLX 		= ./minilibx-linux/libmlx.a

DEPS 		= 	${OBJS:.o=.d}

# DEPS		=	$(addprefix $(DIR_OBJ), $(DEP))

LIBFT		=	./Libft/libft.a

MAIN		=	main.c

CORE		=	images.c calcul.c

PARSING		=	splitUtils.c readFile.c parseUtils.c parseMap.c parseFile.c errors_utils.c

SRCS		=	${MAIN} ${CORE} ${PARSING}

OBJ 		= 	${SRCS:.c=.o}

OBJS		=	$(addprefix $(DIR_OBJ), $(OBJ))

RM			=	rm -f

CC			=	gcc

FLAGS		=	-MMD -Wall -Wextra -Werror -g -I includes 

FLAGS_LIB	= -lXext -lX11

all			: ${NAME}

# %.o: %.c
# 		@${CC} ${FLAGS}  -c $< -o ${<:.c=.o}

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
		${CC} ${FLAGS} -c $< -o $@

${LIBFT}	:
		@echo "\033[35m----Building libft----"
		@make -sC ${LIB_DIR}
		@echo "OK\033[0m"

${MLX}		:
		  @echo "\033[35m----Building MLX----"
		  @make -sC ${MLX_DIR}
		  @echo "OK\033[0m"

${NAME}		: ${OBJS} ${LIBFT} ${MLX}
		@echo "\033[34m----Compiling----"
		@${CC} ${FLAGS} ${OBJS} -L ${MLX_DIR} -lmlx -lm ${FLAGS_LIB} -o ${NAME} ${LIBFT}
		@echo "OK\033[0m"

clean		:
		@echo "\033[31m----Cleaning libft----"
		@make clean -sC ${LIB_DIR}
		@echo "OK"
		@echo "\033[31m----Cleaning MLX----"
		@make clean -sC ${MLX_DIR}
		@echo "OK"
		@echo "\033[31m----Cleaning objects----"
		${RM} ${OBJS} ${DEPS}
		@echo "OK\033[0m"

fclean		: clean
		@echo "\033[33m----Cleaning all----"
		@${RM} ${NAME}
		@${RM} ${LIBFT}
		@${RM} ${MLX}
		@echo "OK\033[0m"

re			: fclean
		@make all

.PHONY		: all clean fclean re

-include $(DEPS)
