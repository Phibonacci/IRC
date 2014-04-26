#ifndef CHAINLIST_H_
# define CHAINLIST_H_

typedef struct s_list t_list;
typedef struct s_item t_item;

union		u_val
{
  int		ival;
  double	dval;
  void		*ptr;
};

struct	s_list
{
  t_item	*first;
  t_item	*end;
  int		count;
};

struct	s_item
{
  int		fd;
  union	u_val	val;
  t_item	*next;
  t_item	*prev;
};

t_list		*list_new(void);
void		item_init_by_default(t_item *this);
void		item_init_by_param(t_item *this, union u_val val,
				   t_item *next, t_item *prev);
void		item_add_at_front(t_list *this, t_item *item);
void		item_add_at_back(t_list *this, t_item *item);
t_item		*item_new_by_default(void);
void		item_remove(t_list *this, t_item *item);
t_item		*item_new_by_param(union u_val val, t_item *next,
				   t_item *prev);

# define ITEMINT(x) (x->val.ival)
# define ITEMDBL(x) (x->val.dval)
# define ITEMPTR(item) (item->val.ptr)
# define ITEMCPTR(item, type) ((type)((item)->val.ptr))

#endif /* !CHAINLIST_H_ */
