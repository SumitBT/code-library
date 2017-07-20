package swishtech.sumitbt.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.sumitbt.models.Role;

public interface RoleRepo  extends CrudRepository<Role, Long>
{
	public Role findByRolename(String rolename);
}
