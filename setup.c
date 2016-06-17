int		init_var(t_main *info)
{
	info->consts.cen_x = WIN_X / 2;
	info->consts.cen_y = WIN_Y / 2;
	info->consts.half_fov = FOV / 2;
	info->consts.beta_inc = FOV / WIN_X;
	info->consts.project_dist = (WIN_X / 2) / (tan(FOV / 2);
	info->player.x = S_X;
	info->player.y = S_Y;
	info->player.a = S_A; 
}
