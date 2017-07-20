package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.Role;

public interface RoleRepo extends CrudRepository<Role, Long>
{
	
}
