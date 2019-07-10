/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

void			send_player_died(t_id *id)
{
	t_msg		newMsg;

	newMsg.mtype = 1;
	newMsg.mtext[0] = PLAYER_DIED;
	newMsg.mtext[1] = '\0';
	if (msgsnd(id->msgid, &newMsg,
		   sizeof(newMsg.mtext), 0) < 0)
		return ;
}

int			read_player_died(t_id *id)
{
	t_msg		newMsg;

	if (msgrcv(id->msgid, &newMsg,
		   sizeof(newMsg.mtext), 0, IPC_NOWAIT) < 0)
		return (0);
	if (newMsg.mtext[0] == PLAYER_DIED)
		return (1);
	return (0);
}
