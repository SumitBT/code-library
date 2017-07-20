package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.Schedule;

public interface ScheduleRepo extends CrudRepository<Schedule, Long>
{

}