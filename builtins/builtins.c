/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:30:12 by msodor            #+#    #+#             */
/*   Updated: 2023/06/12 22:21:09 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtins(t_cmd *cmds, char **env)
{
	if (cmds->cmd[0])
	{
		if (ft_strncmp(cmds->cmd, "echo", ft_strlen(cmds->cmd)) == 0)
			ft_echo(cmds);
		else if (ft_strncmp(cmds->cmd, "env", ft_strlen(cmds->cmd)) == 0)
			ft_env(cmds, env);
		else if (ft_strncmp(cmds->cmd, "pwd", ft_strlen(cmds->cmd)) == 0)
			ft_pwd(cmds);
		else if (ft_strncmp(cmds->cmd, "cd", ft_strlen(cmds->cmd)) == 0)
			ft_cd(cmds);
	}

}