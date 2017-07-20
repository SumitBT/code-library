package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.Registration;

public interface RegistrationRepo extends CrudRepository<Registration, Long>
{

}
