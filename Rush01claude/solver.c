typedef struct s_position {
	int row;
	int col;
	int num;
	int size;
} t_position;

typedef struct s_solver_context {
    int **grid;
    int *views;
    int size;
    int row;
    int col;
} t_solver_context;

int		is_valid_position(int **grid, t_position pos);
int		check_views(int **grid, int *views, int size);
// Add these function declarations
int check_row_views(int **grid, int *views, int size, int row);
int check_col_views(int **grid, int *views, int size, int col);

// ... existing functions remain the same

// Forward declaration
int	solve_impl(t_solver_context *ctx);

// Optimized: Check if placing this number would immediately violate view constraints
int	is_immediately_invalid(t_solver_context *ctx, int num)
{
	int	temp;
	int	result;
	
	// Store original value
	temp = ctx->grid[ctx->row][ctx->col];
	ctx->grid[ctx->row][ctx->col] = num;
	
	// Check if current row is complete and violates views
	if (ctx->col == ctx->size - 1)
	{
		result = check_row_views(ctx->grid, ctx->views, ctx->size, ctx->row);
		ctx->grid[ctx->row][ctx->col] = temp;
		return (!result);
	}
	
	// Check if current column is complete and violates views
	if (ctx->row == ctx->size - 1)
	{
		result = check_col_views(ctx->grid, ctx->views, ctx->size, ctx->col);
		ctx->grid[ctx->row][ctx->col] = temp;
		return (!result);
	}
	
	ctx->grid[ctx->row][ctx->col] = temp;
	return (0);
}

int	handle_next_row(t_solver_context *ctx)
{
	t_solver_context next_ctx;

	next_ctx.grid = ctx->grid;
	next_ctx.views = ctx->views;
	next_ctx.size = ctx->size;
	next_ctx.row = ctx->row + 1;
	next_ctx.col = 0;
	return (solve_impl(&next_ctx));
} 

int	try_numbers(t_solver_context *ctx)
{
	int			num;
	t_position	pos;
	t_solver_context next_ctx;

	num = 1;
	while (num <= ctx->size)
	{
		pos.row = ctx->row;
		pos.col = ctx->col;
		pos.num = num;
		pos.size = ctx->size;
		if (is_valid_position(ctx->grid, pos) && !is_immediately_invalid(ctx, num))
		{
			ctx->grid[ctx->row][ctx->col] = num;
			next_ctx.grid = ctx->grid;
			next_ctx.views = ctx->views;
			next_ctx.size = ctx->size;
			next_ctx.row = ctx->row;
			next_ctx.col = ctx->col + 1;
			if (solve_impl(&next_ctx))
				return (1);
			ctx->grid[ctx->row][ctx->col] = 0;
		}
		num++;
	}
	return (0);
}

int	solve_impl(t_solver_context *ctx)
{
	if (ctx->row == ctx->size)
		return (check_views(ctx->grid, ctx->views, ctx->size));
	if (ctx->col == ctx->size)
		return (handle_next_row(ctx));
	return (try_numbers(ctx));
}

int		solve(int **grid, int *views, int size)
{
	t_solver_context ctx;

	ctx.grid = grid;
	ctx.views = views;
	ctx.size = size;
	ctx.row = 0;
	ctx.col = 0;
	return (solve_impl(&ctx));
}