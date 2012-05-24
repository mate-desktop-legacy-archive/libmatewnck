


#ifndef __MATEWNCK_ENUM_TYPES_H__
#define __MATEWNCK_ENUM_TYPES_H__

G_BEGIN_DECLS


/* enumerations from "pager.h" */
#define MATEWNCK_TYPE_PAGER_DISPLAY_MODE matewnck_pager_display_mode_get_type()
GType matewnck_pager_display_mode_get_type (void);
#define MATEWNCK_TYPE_PAGER_LAYOUT_POLICY matewnck_pager_layout_policy_get_type()
GType matewnck_pager_layout_policy_get_type (void);

/* enumerations from "screen.h" */
#define MATEWNCK_TYPE_MOTION_DIRECTION matewnck_motion_direction_get_type()
GType matewnck_motion_direction_get_type (void);
#define MATEWNCK_TYPE___MATEWNCK_LAYOUT_ORIENTATION _matewncklayoutorientation___matewnck_layout_orientation_get_type()
GType _matewncklayoutorientation___matewnck_layout_orientation_get_type (void);
#define MATEWNCK_TYPE___MATEWNCK_LAYOUT_CORNER _matewncklayoutcorner___matewnck_layout_corner_get_type()
GType _matewncklayoutcorner___matewnck_layout_corner_get_type (void);

/* enumerations from "tasklist.h" */
#define MATEWNCK_TYPE_TASKLIST_GROUPING_TYPE matewnck_tasklist_grouping_type_get_type()
GType matewnck_tasklist_grouping_type_get_type (void);

/* enumerations from "util.h" */
#define MATEWNCK_TYPE_CLIENT_TYPE matewnck_client_type_get_type()
GType matewnck_client_type_get_type (void);

/* enumerations from "window.h" */
#define MATEWNCK_TYPE_WINDOW_STATE matewnck_window_state_get_type()
GType matewnck_window_state_get_type (void);
#define MATEWNCK_TYPE_WINDOW_ACTIONS matewnck_window_actions_get_type()
GType matewnck_window_actions_get_type (void);
#define MATEWNCK_TYPE_WINDOW_TYPE matewnck_window_type_get_type()
GType matewnck_window_type_get_type (void);
#define MATEWNCK_TYPE_WINDOW_GRAVITY matewnck_window_gravity_get_type()
GType matewnck_window_gravity_get_type (void);
#define MATEWNCK_TYPE_WINDOW_MOVE_RESIZE_MASK matewnck_window_move_resize_mask_get_type()
GType matewnck_window_move_resize_mask_get_type (void);
G_END_DECLS

#endif /* __MATEWNCK_ENUM_TYPES_H__ */



