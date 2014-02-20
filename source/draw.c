/*
 * pseudocode for main loop; TODO larger brush than one pixel
 *
 * 	Point pos
 * 	Color temp
 * 	int pal_index
 *
 * 	while (!start_button) {
 * 		if (!a_button)
 * 			vram[pos.y][pos.x] = temp
 *
 * 		pos.y += tribool_horiz
 * 		pos.y = max(pos.y, 0)
 * 		pos.y = min(pos.y, MAX_Y)
 *
 * 		pos.x += tribool_vert
 * 		pos.x = max(pos.x, 0)
 * 		pos.x = min(pos.x, MAX_X)
 *
 * 		pal_index += tribool_shoulder
 * 		pal_index &= 0xf
 *
 * 		vram[pos.y][pos.x] = PALLETTE[pal_index]
 *
 * 		vblank()
 * 	}
 *
 */
