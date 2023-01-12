/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:40 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/12 14:55:25 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_var_renderer(t_cub3d *wall_renderer)
{
	wall_renderer->player_size = 32;       // a mettre en define
	wall_renderer->wall_size = 64;       // a mettre en define
	wall_renderer->fov = 90;       // a mettre en define
	wall_renderer->v_dir_x = -1; // modifier ces val en fonction des pts cardinaux
	wall_renderer->v_dir_y = 0;
	wall_renderer->v_camera_plane_y = 0.60; // en foncton du fov?? // tatonnement
	wall_renderer->v_camera_plane_x = 0;	
}

// NE PAS OUBLIER D ARRONDR AVE FLOOR
void	init_orientation_from_player(t_cub3d *wall_renderer)
{
	if()
}

// récupérer N / S / E/ W pour obtenir la pos du joueur
// sauvegarder dir et pos et remplacer par 0;
// générer le vecteur direction en fonction du symbole N / S / E / W
// générer le vecteur plan de caméra
// envoyer des rayons de guche à droite (un par pixel en fonction de la résolution)
// depuis la pos du joueur
// calculer la distance jouer / mur en charchat si le rayon a touché un mur
// établir le ratio entre la distance et la taille de la colonne de pixel
// définir les variables permettant de dessiner le mur (ligne haute, point de départ, position de fin)