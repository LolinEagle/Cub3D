/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:40 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/12 20:01:15 by sam              ###   ########.fr       */
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

// NE PAS OUBLIER D ARRONDIR AVEC FLOOR
void	init_orientation_from_player(t_cub3d *wall_renderer)
{
	if()
}

// tester en statique:
// récupérer N / S / E/ W avec les coordonnées x et y pour l'orientation de départ
// sauvegarder dir et pos et remplacer la lettre par 0 (point de départ)
// envoyer des rayons de gauche à droite (un par pixel en fonction de la résolution) depuis la pos du joueur
// générer le vecteur plan de caméra à partir de distance
// générer dir 
// en déduire la distance
// établir le ratio entre la distance et la taille de la colonne de pixel
// définir les variables permettant de dessiner le mur (ligne haute, point de départ, position de fin)


// gestion du mouvement ds les  directions avant/arrière, droite/gauche et de la rotation:
// générer le vecteur direction en fonction des keycodes