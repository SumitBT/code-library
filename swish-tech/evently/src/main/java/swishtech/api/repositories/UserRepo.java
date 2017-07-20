package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.User;

public interface UserRepo extends CrudRepository<User, Long>
{
	public User findByEmail(String email);
	
	public Iterable<User> findByRoleId(long id);
}
