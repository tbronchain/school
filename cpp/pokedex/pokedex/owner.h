#ifndef OWNER_H
# define OWNER_H

class	owner
{
public:
	// canonical class
						owner(const QString&, const QString&);
						~owner();
						owner(const owner&);
	owner&				operator=(const owner&);

	// getters
	const QString&		getName(void) const;
	const QString&		getAvatar(void) const;

	// setter
	void				setAvatar(const QString&);

private:
	QString				_oname;
	QString				_avatar;
};

#endif // OWNER_H
